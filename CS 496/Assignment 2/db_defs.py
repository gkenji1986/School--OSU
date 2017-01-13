from google.appengine.ext import ndb

class orderEntry(ndb.Model):
	customerName = ndb.StringProperty(required=True)
	processorClass = ndb.StringProperty(required=False)
	graphics = ndb.StringProperty(required=False)
	ssd = ndb.StringProperty(required=False)
	extras = ndb.StringProperty(required=False)