const mysql = require('mysql');

const con = mysql.createConnection({
  host     : "<host-url>",
  user     : "<username>"
  password : "<password>",
  port     : 3306
});

exports.handler = async (event) => {
  con.query("CREATE DATABASE mysqllab", function (err, result) {
    if (err) throw err;
    console.log("Database created");
  });
  return "Database Created"
};

// npm init -y
// npm install --save mysql
