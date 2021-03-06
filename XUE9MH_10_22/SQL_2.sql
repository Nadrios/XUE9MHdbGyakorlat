CREATE TABLE GYARTO(
adoszam INT PRIMARY KEY,
nev CHAR(30),
telephely VARCHAR(0) NULL,
irsz CHAR(4),
varos CHAR(40),
utca CHAR(100));
CREATE TABLE TERMEK(
tkod INT PRIMARY KEY,
nev CHAR(50),
ear numeric CHECK(ear > 0),
gyarto INT REFERENCES GYARTO);
CREATE TABLE Egysegek(
aru NUMERIC REFERENCES TERMEK,
db NUMERIC CHECK ( db > 0));
CREATE TABLE Alkatresz(
akod NUMERIC PRIMARY KEY,
nev CHAR(50));
CREATE TABLE Komponens(
termek NUMERIC REFERENCES TERMEK,
alkatresz NUMERIC REFERENCES Alkatresz);
