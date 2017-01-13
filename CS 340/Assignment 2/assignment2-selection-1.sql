--Created by: Grant Nakashima
--Assignment: Assignment2-selection.sql
--Due Date: 2/14/16

--1 Find all films with maximum length and minimum rental duration 
--(compared to all other films). In other words let L be the maximum film length, 
--and let R be the minimum rental duration in the table film. 
--You need to find all films with length L and rental duration R.
--You just need to return attribute film id for this query.

SELECT f.film_id FROM film f 
WHERE f.length=(SELECT MAX(f.length) FROM film f)
AND f.rental_duration=(SELECT MIN(f.rental_duration) FROM film f)

--2 We want to find out how many actors have played in each film, so for each film return the film id,
--film title, and the number of actors who played in that film. Some films may have no actors, 
--and your query does not need to return those films.

SELECT f.film_id, f.title, COUNT(fa.actor_id) AS Actor_Number FROM actor a
INNER JOIN film_actor fa ON a.actor_id = fa.actor_id
INNER JOIN film f ON fa.film_id = f.film_id
INNER JOIN film_category fc ON f.film_id = fc.film_id
INNER JOIN category c ON fc.category_id=c.category_id
GROUP BY f.film_id
HAVING COUNT(fa.actor_id) > 0

--3 Find the average length of films for each language. 
--Your query should return every language even if there is no films in that language. 
--Language refers to attribute language_id (not attribute original_language_id)

SELECT T1.name, T2.average FROM 
(SELECT l.name, l.language_id FROM language l) AS T1
LEFT JOIN
(SELECT f.language_id, AVG(f.length) AS average FROM film f
INNER JOIN language l ON l.language_id = f.language_id
WHERE l.language_id=f.language_id
GROUP BY f.language_id) AS T2
ON T1.language_id=T2.language_id

--4 We want to find out how many of each category of film KEVIN BLOOM has started 
--in so return a table with category.name and the count of the number of films that 
--KEVIN was in which were in that category order by the category name ascending 
--(Your query should return every category even if KEVIN has been in no films in 
--that category).

SELECT T1.name, T2.Number_Of_Categories 
FROM
	(SELECT c.name
	 FROM category c) AS T1
LEFT JOIN
(SELECT c.name, COUNT(c.name) AS Number_Of_Categories FROM actor a 
INNER JOIN film_actor fa ON a.actor_id = fa.actor_id
INNER JOIN film f ON fa.film_id = f.film_id
INNER JOIN film_category fc ON f.film_id = fc.film_id
INNER JOIN category c ON fc.category_id=c.category_id
WHERE a.first_name = 'KEVIN' AND a.last_name='BLOOM'
GROUP BY c.name
ORDER BY c.name ASC) AS T2
ON T1.name=T2.name

--5 Find the film title of all films which do not feature both SCARLETT DAMON 
--and BEN HARRIS(so you will not list a film if both of these actors have played in that film, 
--but if only one of these actors have played in a film, that film should be listed).
--Order the results by title, descending (use ORDER BY title DESC at the end of the query)
--Warning, this is a tricky one and while the syntax is all things you know, you have to think oustide
--the box a bit to figure out how to get a table that shows pairs of actors in movies 

SELECT f.title FROM actor a
	INNER JOIN film_actor fa ON a.actor_id = fa.actor_id
    INNER JOIN film f ON fa.film_id = f.film_id
	WHERE f.title NOT IN 

(SELECT T1.title FROM

(SELECT f.title 
    FROM actor a 
	INNER JOIN film_actor fa ON a.actor_id = fa.actor_id
    INNER JOIN film f ON fa.film_id = f.film_id
    WHERE a.first_name='BEN' AND a.last_name='HARRIS') AS T1
	
INNER JOIN

(SELECT f.title
    FROM actor a
	INNER JOIN film_actor fa ON a.actor_id = fa.actor_id
    INNER JOIN film f ON fa.film_id = f.film_id
    WHERE a.first_name='SCARLETT' AND a.last_name='DAMON') AS T2
	
ON T1.title=T2.title)
GROUP BY f.title	
ORDER BY f.title DESC