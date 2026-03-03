# Write your MySQL query statement below
select round(
    count(distinct a.player_id) /
    (select count(distinct player_id) from activity)
, 2) as fraction
from activity a
join (
    select player_id, min(event_date) as first_login
    from activity
    group by player_id
) f
on a.player_id = f.player_id
and datediff(a.event_date, f.first_login) = 1;
