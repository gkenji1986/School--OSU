var mysql = require('mysql');

var pool = mysql.createPool({
  port: '3306',
  host  : '127.0.0.1',
  user  : 'capstoneuser',
  password: 'capstone123',
  database: 'capstone'
});

module.exports = pool;