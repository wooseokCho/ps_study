select i.animal_id, i.name
from animal_ins i
left join animal_outs o 
on i.animal_id = o.animal_id
where o.datetime < i.datetime
order by i.datetime
