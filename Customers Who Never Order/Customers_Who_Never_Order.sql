# Write your MySQL query statement below
# Runtime: 261 ms, faster than 40.78% of MySQL online submissions for Customers Who Never Order.

SELECT Name as Customers
FROM Customers
WHERE id NOT IN
(
SELECT t1.id
FROM Customers t1
INNER JOIN Orders t2
ON t1.Id = t2.CustomerId
);