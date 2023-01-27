
CREATE DATABASE company;

USE school;

CREATE TABLE employee(Worker_ID NUMERIC(5,0) NOT NULL PRIMARY KEY, Name VARCHAR(26), Birthday DATE, Salary NUMERIC(5,2), Email VARCHAR(40));

DESCRIBE employee;
