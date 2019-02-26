# Write your MySQL query statement below
# Runtime: 188 ms, faster than 100.00% of MySQL online submissions for Classes More Than 5 Students.
select class from courses group by class having count(distinct student) >= 5;
