# Write your MySQL query statement below
# Runtime: 544 ms, faster than 92.21% of MySQL online submissions for Delete Duplicate Emails.
delete from Person where Id not in
(
    select temp.Id
    From
    (
        select MIN(Id) as Id
        FROM Person
        GROUP BY Email        
    )
    as temp
);
