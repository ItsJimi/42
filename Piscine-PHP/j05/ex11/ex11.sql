SELECT UPPER(nom) AS NOM, prenom, prix FROM (fiche_personne fp INNER JOIN membre m ON fp.id_perso=m.id_fiche_perso) NATURAL JOIN abonnement;
