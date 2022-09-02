const mysql2 = require("mysql2");
const express = require("express");

const app = express();
var results;
app.use(express.json());

var con = mysql2.createConnection({
  host: "localhost",
  user: "root",
  password: "12345678",
  database: "demo",
});

function GetData() {
  con.connect((err) => {
    if (err) throw err;
    con.query("SELECT * FROM users", (err, result, fields) => {
      if (err) throw err;
      results = result;
      //   console.log(results);
      return result;
    });
  });
}

function GetDatawithName(Name) {
  con.connect((err) => {
    if (err) throw err;
    con.query("SELECT * FROM users", (err, result, fields) => {
      if (err) throw err;
      //   console.log(results);
      results = result;
      //   return result;
    });
  });
}

function PostData(ID, Name, dept) {
  con.connect((err) => {
    if (err) throw err;
    con.query(
      "INSERT INTO users VALUES(?, ? , ?);",
      [ID, Name, dept],
      (err, fields) => {
        if (err) throw err;
        // console.log(result);
      }
    );
  });
}

app.get("/api/courses", (req, res) => {
  GetData();
  res.send(results);
});

app.get("/api/courses/:name", (req, res) => {
  GetDatawithName(req.params.name.toString());
  const result = results.find((c) => c.name === req.params.name);
  if (!result) return res.status(404).send("The field is invalid");
  res.send(result);
});

app.post("/api", (req, res) => {
  PostData(req.body.id, req.body.name, req.body.dept);
  return res.status(200).send("Successfully updated");
});

const port = process.env.PORT || 5000;
app.listen(port, () => console.log(`Listenting on port ${port}`));
