-- Création de la base CRAB
-- Suppression des tables existantes
Drop table if exists TECHNICIEN;
Drop table if exists STATION;
Drop table if exists BORNE;
Drop table if exists TYPEINCIDENT;
Drop table if exists INCIDENT;
Drop table if exists INTERVENTION;

-- Création des tables

-- Création table typeBorne
-- intervalRevision : nombre de jours entre deux révision 
-- nbr d'unité de recharge
create table TYPEBORNE(
	id tinyint,
	libelle varchar(20),
	dureeRevision smallint,
	intervalRevision smallint,
	nbrUniteRecharge smallint,
	primary key(id)
)engine=innodb charset=UTF8;

-- Création table Technicien
create table TECHNICIEN(
	id smallint,
	nom varchar(30),
	prenom varchar(30),
	primary key (id)
)engine=innodb charset=UTF8;


-- Création table Station
create table STATION(
	id smallint,
	nom varchar(30),
	adresseRue varchar(50),
	coordLat float,
	coordLong float,
	primary key (id)
)engine=innodb charset=UTF8;


-- Création table Borne
-- Le champ état prend la valeur « HS » ou « ES » selon que la borne est hors service ou en service.
-- Elle est hors service dès qu'un incident est en cours de traitement sur cette borne.
create table BORNE(
	id smallint,
	etat varchar(2), 
	dateMiseEnService date,
	dateDerniereRevision date,
	idStation smallint,
	idTypeBorne tinyint,
	primary key (id)
	-- Clé étrangère : idStation en référence à id de STATION
)engine=innodb charset=UTF8;


-- Création table typeIncident
create table TYPEINCIDENT(
	id tinyint,
	description varchar(100),
	tempsReparationPrevu smallint, -- exprimé en nombre de minutes
	primary key (id)
)engine=innodb charset=UTF8;


-- Création table Incident
create table INCIDENT(
	id smallint,
	remarques varchar(100),
	dateHeure datetime,
	dateHeureCloture datetime, -- renseigné lorsque l’incident est clôturé
	idBorne smallint,
	idType tinyint, -- n’est pas renseigné si le type de l’incident n’est pas un incident déjà connu.
	primary key (id)
	-- Clé étrangère : idBorne en référence à id de BORNE 
	-- Clé étrangère : idType en référence à id de TYPEINCIDENT
)engine=innodb charset=UTF8;


-- Création table Intervention
create table INTERVENTION(
	id smallint,
	dateHeureDebut datetime,
	dateHeureFin datetime,
	idIncident smallint,
	idTechnicien smallint,
	primary key (id)
	-- Clé étrangère : idIncident en référence à id de INCIDENT
	-- Clé étrangère : idTechnicien en référence à id de TECHNICIEN
)engine=innodb charset=UTF8;


-- Liaisons des tables

-- Clé étrangère : BORNE.idStation en référence à id de STATION
Alter table BORNE
	add foreign key (idStation) references STATION(id);

-- Clé étrangère : INCIDENT.idBorne en référence à id de BORNE
-- Clé étrangère : INCIDENT.idType en référence à id de TYPEINCIDENT
Alter table INCIDENT
	add foreign key (idBorne) references BORNE(id),
	add foreign key (idType) references TYPEINCIDENT(id);

-- Clé étrangère : INTERVENTION.idIncident en référence à id de INCIDENT
-- Clé étrangère : INTERVENTION.idTechnicien en référence à id de TECHNICIEN
Alter table INTERVENTION
	add foreign key (idIncident) references INCIDENT(id),
	add foreign key (idTechnicien) references TECHNICIEN(id);
	
-- Clé étrangère : BORNE.idTypeBorne en référence à id de TYPEBORNE
Alter table BORNE
	add foreign key (idTypeBorne) references TYPEBORNE(id);
