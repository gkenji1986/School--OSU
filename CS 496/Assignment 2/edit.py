import webapp2
import os
import jinja2
from google.appengine.ext import ndb
import base_page
import db_defs

class Edit(base_page.MainHandler):

	def __init__(self, request, response):
		self.initialize(request, response)
		self.template_variables={}

	def get(self):
		action = self.request.get('action')
		order_key = ndb.Key(urlsafe=self.request.get('key'))
		order = order_key.get()

		if action == 'edit_order':
			if self.request.get('customerName') == "":
				self.template_variables['message'] = "Name Necessary"
			else:
				order.customerName = self.request.get('customerName')
				order.processorClass = self.request.get('processorClass')
				order.graphics = self.request.get('graphics')
				order.ssd = self.request.get('ssd')
				order.extras = self.request.get('extras')
				order.put()
		self.template_variables['order'] = order
		self.template_variables['order_key'] = self.request.get('key')
		self.render('edit.html', self.template_variables)