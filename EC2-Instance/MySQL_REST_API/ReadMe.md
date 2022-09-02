Use EC2-Instance UBUNTU as VM


step 1 : Install MySQL
  sudo apt update
  sudo apt install mysql-server
  sudo systemctl start mysql.service

step 2 : Add USER on mysql
  sudo mysql
  ALTER USER 'root'@'localhost' IDENTIFIED WITH mysql_native_password BY 'password';
  exit
  mysql -u root -p

step 3 : Install NodeJS
  sudo apt install nodejs

step 4 :
  mkdir <Project-Name>
  npm init -y
  npm i mysql2
  npm i nodemon
  npm i express

step 5 : copy index.js

step 6 : nodemon index.js

step 7 : Edit Security Group Rule
IP-version          Type          Protocol     Port-range   Source
  IPv6	         MYSQL/Aurora	       TCP	        3306	     ::/0
  IPv6	         MYSQL/Aurora	       TCP	        3306       0.0.0.0/0
  IPv6	           HTTPS	           TCP	        443	       0.0.0.0/0
  IPv6	           HTTPS	           TCP	        443	       ::/0
  IPv6	           HTTP	             TCP	         80	       0.0.0.0/0
  IPv6	           HTTP	             TCP	         80	       ::/0
