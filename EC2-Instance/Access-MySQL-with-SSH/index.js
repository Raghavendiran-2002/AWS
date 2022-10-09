const { readFileSync } = require("fs");
const mysqlssh = require("mysql-ssh");
const express = require("express");
const mysql = require("mysql2");
const { Client } = require("ssh2");

const app = express();

const conn = new Client();
conn
  .on("ready", () => {
    console.log("Client :: ready");
    conn.exec("uptime", (err, stream) => {
      if (err) throw err;
      stream
        .on("close", (code, signal) => {
          console.log(
            "Stream :: close :: code: " + code + ", signal: " + signal
          );
          conn.end();
        })
        .on("data", (data) => {
          console.log("STDOUT: " + data);
        })
        .stderr.on("data", (data) => {
          console.log("STDERR: " + data);
        });
    });
  })
  .connect({
    host: "3.108.250.77",
    port: 22,
    username: "ubuntu",
    privateKey: readFileSync(
      "/Users/raghavendiran/Development/AWS/EC2_Projects/MySQL/AWS_MySql.pem"
    ),
  });

// create the connection to database
// const connection = mysql.createConnection({
//   host: "localhost",
//   user: "root",
//   database: "12345678",
// });

// // simple query
// connection.query(
//   'SELECT * FROM `table` WHERE `name` = "Page" AND `age` > 45',
//   function (err, results, fields) {
//     console.log(results); // results contains rows returned by server
//     console.log(fields); // fields contains extra meta data about results, if available
//   }
// );

// mysqlssh
//   .connect(
//     {
//       host: "3.108.250.77",
//       user: "ubuntu",
//       privateKey: fs.readFileSync(
//         "/Users/raghavendiran/Development/AWS/EC2_Projects/MySQL/AWS_MySql.pem"
//       ),
//     },
//     {
//       host: "127.0.0.1",
//       user: "root",
//       password: "12345678",
//       database: "demo",
//     }
//   )
//   .then((client) => {
//     client.query(
//       "Create table users(id INT(20), name VARCHAR(30), dept VARCHAR(30));",
//       function (err, results, fields) {
//         if (err) throw err;
//         console.log(results);
//         mysqlssh.close();
//       }
//     );
//   })
//   .catch((err) => {
//     console.log(err);
//   });

app.get("/", async (req, res) => {
  res.status(200).send("SuccessFul");
});

app.use((req, res, next) => {
  res.status(404).render("404", { title: "404" });
  next();
});

app.listen(3000, () => console.log("Listening on port 3000..."));
