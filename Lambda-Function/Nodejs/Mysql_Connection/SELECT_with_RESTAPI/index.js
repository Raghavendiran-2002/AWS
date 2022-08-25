const mysql = require('mysql');

const con = mysql.createConnection({
   host: process.env.LAMBDA_HOSTNAME,
   user: process.env.LAMBDA_USERNAME,
   password: process.env.LAMBDA_PASSWORD,
   port: process.env.LAMBDA_PORT,
   connectionLimit: 10,
   multipleStatements: true,
   // Prevent nested sql statements
   connectionLimit: 1000,
   connectTimeout: 60 * 60 * 1000,
   acquireTimeout: 60 * 60 * 1000,
   timeout: 60 * 60 * 1000,
   debug: true,
   database:'testdb'
});

exports.handler = (event, context, callback) => {
   console.log('inside lambda...'+event.emp_id)
  // allows for using callbacks as finish/error-handlers
  context.callbackWaitsForEmptyEventLoop = false;
  const sql = "select * from Employee where emp_id = " + event.emp_id;
  con.query(sql, function (err, result) {
  if (err) throw err;
    callback(null, result)
   });
};
