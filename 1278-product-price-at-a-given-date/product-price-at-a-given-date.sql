# Write your MySQL query statement below
select p.product_id, COALESCE(f.new_price,10) as price
from (select distinct product_id from products) p
left join (
    select p1.product_id, p1.new_price
    from products p1
    join (
        select product_id, max(change_date) as change_date
        from products
        where change_date <= '2019-08-16'
        group by product_id
    ) t
    on p1.product_id = t.product_id
    and p1.change_date = t.change_date
) f
on p.product_id = f.product_id;