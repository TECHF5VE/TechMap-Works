CREATE TABLE 'user' (
(name VARCHAR(20), password VARCHAR(20));
INSERT INTO login_user (name,password) VALUES ('andy','123456');
INSERT INTO sarracenia_demo01 (name,password) VALUES ('admin','123456');

CREATE TABLE pet (name VARCHAR(20), owner VARCHAR(20)£©£»
    -> species VARCHAR(20), sex CHAR(1), birth DATE, death DATE);

CREATE TABLE 'user' (
  'id' INT NOT NULL AUTO_INCREMENT,
  'name' VARCHAR(45) NOT NULL,
  'password' VARCHAR(45) NULL,
  PRIMARY KEY ('id'));