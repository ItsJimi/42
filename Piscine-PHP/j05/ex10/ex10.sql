SELECT titre AS Titre, resum AS Resume, annee_prod FROM film A INNER JOIN genre B ON A.id_genre=B.id_genre WHERE B.nom='erotic' ORDER BY annee_prod DESC;
