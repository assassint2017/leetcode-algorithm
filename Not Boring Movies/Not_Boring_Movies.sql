# Write your MySQL query statement below
# Runtime: 118 ms, faster than 97.65% of MySQL online submissions for Not Boring Movies.
SELECT * 
FROM cinema
WHERE id MOD 2 = 1 AND description <> 'boring'
ORDER BY rating DESC;