# Write your MySQL query statement below
select distinct p.product_id,
       case when f.new_price is not null then f.new_price else 10 end as price
from products p
left join (
    select p1.product_id, p1.new_price, p1.change_date
    from products p1
    join (
        select product_id, max(change_date) as change_date
        from products
        where change_date <= '2019-08-16'
        group by product_id
    ) x
    on p1.product_id = x.product_id and p1.change_date = x.change_date
) f
on p.product_id = f.product_id;