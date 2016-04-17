#!/usr/bin/env python

import webapp2

app = webapp2.WSGIApplication([
	('/edit','edit.Edit'),
	('/delete', 'delete.Delete'),
    ('/', 'base_page.MainHandler')
	], debug=True)
