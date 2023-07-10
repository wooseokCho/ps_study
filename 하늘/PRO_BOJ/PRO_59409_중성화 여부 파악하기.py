SELECT animal_id, name, 
case sex_upon_intake 
when 'Neutered Male' then 'O'
when 'Neutered Female' then 'O'
when 'Spayed Female' then 'O'
when 'Spayed Male' then 'O'
else 'X'
End as '중성화'

from animal_ins
