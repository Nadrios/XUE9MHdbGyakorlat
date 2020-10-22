CREATE TABLE Tanfolyam(
tkod INT PRIMARY KEY,
ar NUMERIC,
tipus CHAR(25),
megnevezes CHAR(25));
CREATE TABLE Resztvevo(
tajszam INT PRIMARY KEY,
nev CHAR(25),
lakcim VARCHAR(50));
CREATE TABLE TR(
tanfolyam NUMERIC REFERENCES Tanfolyam,
befizetes INT,
resztvevo NUMERIC REFERENCES Resztvevo);