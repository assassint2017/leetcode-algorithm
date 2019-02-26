-- Write your MySQL query statement below
-- Runtime: 276 ms, faster than 6.52% of MySQL online submissions for Combine Two Tables.
select t1.FirstName, t1.LastName, t2.City, t2.State
from Person t1
left outer join Address t2
on t1.PersonId = t2.PersonId;