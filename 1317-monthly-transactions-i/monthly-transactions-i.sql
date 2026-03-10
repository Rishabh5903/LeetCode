# Write your MySQL query statement below
select substring(trans_Date,1,7) as month, country, count(id) as trans_count, sum(state='approved') as approved_count, sum(amount) as trans_total_amount, 
sum(amount * (case when state='approved' then 1 else 0 end)) as approved_total_amount
from transactions
group by country, substring(trans_date,1,7)