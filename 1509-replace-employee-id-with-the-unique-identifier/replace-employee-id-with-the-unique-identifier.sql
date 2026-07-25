# Write your MySQL query statement below
select eu.unique_id, e.name
FROM Employees e
LEft JOIN EMployeeUNI eu
  ON e.ID = eu.id;