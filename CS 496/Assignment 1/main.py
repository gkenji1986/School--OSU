#!/usr/bin/env python
#
# Copyright 2007 Google Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
import webapp2
import cgi
import string
import datetime

html_text = """
<!DOCTYPE html>
<html lang="en">
	<head>
		<meta charset="utf=8"/>
	</head>
	  <body>
		<h1>Which do you want: time or date?</h1>
		<form action="/timedate" method="post">
		  <div><input type="radio" name="dt" value="time"/>Time </div>
		  <div><input type="radio" name="dt" value="date"/>Date </div>
		  <div><input type="submit" value="Get Result" onClick="resetButton();"></div>
		</form>
	  </body>
</html>
"""

class MainHandler(webapp2.RequestHandler):
    def get(self):
        self.response.write(html_text)

class TimeDate(webapp2.RequestHandler):
    def post(self):
		now = datetime.datetime.now()
		currenttime = self.request.get("dt")
		date = self.request.get("dt")
		if currenttime is not None and currenttime != '' and currenttime == "time":
			self.response.out.write('<html><body>The current time is:<pre>')
			self.response.out.write(now.strftime("%H:%M:%S"))
			self.response.out.write('</pre></body></html>')
		elif date is not None and date != '' and date == "date":
			self.response.out.write('<html><body>The current date is:<pre>')
			self.response.out.write(now.strftime("%d/%m/%Y"))
			self.response.out.write('</pre></body></html>')
		
app = webapp2.WSGIApplication([('/', MainHandler),('/timedate', TimeDate)], debug=True)

