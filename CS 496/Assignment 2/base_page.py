import webapp2
import os
import jinja2
from google.appengine.ext import ndb
import db_defs

class MainHandler(webapp2.RequestHandler):
	
	@webapp2.cached_property
	def jinja2(self):
		return jinja2.Environment(
			loader=jinja2.FileSystemLoader(os.path.dirname(__file__) + '/templates'),
			extensions=['jinja2.ext.autoescape'],
			autoescape=True
			)

	template_variables = {}

	def __init__(self, request, response):
		self.initialize(request, response)
		self.template_variables = {}

	def render(self, template, template_variables={}):
		template=self.jinja2.get_template(template)
		self.response.write(template.render(template_variables))

	def get(self):
		self.template_variables['orders'] = [{'customerName': x.customerName, 'processorClass': x.processorClass, 'graphics': x.graphics, 'ssd': x.ssd, 'extras': x.extras, 'key': x.key.urlsafe()} for x in db_defs.orderEntry.query(ancestor=ndb.Key(db_defs.orderEntry, 'base-data')).fetch()]
		self.render('index.html', self.template_variables)

	def post(self):
		action = self.request.get('action')
		
		if action == 'add_order':
			if self.request.get('customerName') == "":
				self.template_variables['message'] = "Name necessary"
			else:
				k = ndb.Key(db_defs.orderEntry, 'base-data')
				order = db_defs.orderEntry(parent=k)

				order.customerName = self.request.get('customerName')
				order.processorClass = self.request.get('processorClass')
				order.graphics = self.request.get('graphics')
				order.ssd = self.request.get('ssd')
				order.extras = self.request.get('extras')
				order.put()

			self.template_variables['orders'] = [{'customerName': x.customerName, 'processorClass': x.processorClass, 'graphics': x.graphics, 'ssd': x.ssd, 'extras': x.extras, 'key': x.key.urlsafe()} for x in db_defs.orderEntry.query(ancestor=ndb.Key(db_defs.orderEntry, 'base-data')).fetch()]
			self.render('index.html', self.template_variables)
	