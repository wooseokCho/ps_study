
SELECT i.ANIMAL_ID, i.ANIMAL_TYPE, i.NAME
from animal_ins i
left join animal_outs o
on i.animal_id = o.animal_id
where  i.SEX_UPON_INTAKE like 'intact%' and  o.SEX_UPON_OUTCOME in ('Spayed Female', 'Spayed Female' , 'Neutered Male', 'Neutered Female');
