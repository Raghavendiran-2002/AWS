const mysql = require('mysql');

const con = mysql.createConnection({
  host     : "<host-url>",
  user     : "<username>"
  password : "<password>",
  port     : 3306
  database : "<DatabaseName>"
});


exports.handler = (event, context, callback) => {
 // allows for using callbacks as finish/error-handlers
 context.callbackWaitsForEmptyEventLoop = false;
 const sql = "insert into Employee values(1,'Vaquar khan');" // "insert into testdb.Employee values(1,'Vaquar khan');"
 con.query(sql, (err, res) => {
    if (err) {
    throw err
  }
callback(null, '1 records inserted.');
 })
};
