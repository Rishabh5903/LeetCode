# Write your MySQL query statement below
select round(100* (count(d1.customer_id)/(select count(distinct customer_id) from delivery)), 2) as immediate_percentage
from delivery d1
join (
    select customer_id, min(order_date) as first_order
    from delivery
    group by customer_id
) f
on d1.customer_id=f.customer_id and d1.order_date=f.first_order and d1.customer_pref_delivery_date=f.first_order