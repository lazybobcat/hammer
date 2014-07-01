SLB.using(SLB);

local w = World.Instance();
local wave = 9;
local rabbit = 1;
local tentacle = 2;
local crawler = 3;

for i=0,10 do
	w:AddCreature(crawler, 10 + 70*i);
	w:AddCreature(crawler, -20 - 70*i);
end

for i=0,10 do
	w:AddCreature(crawler, 500 + 80*i);
	w:AddCreature(crawler, -500 - 80*i);
end

for i=0,10 do
	w:AddCreature(crawler, 1500 + 90*i);
	w:AddCreature(tentacle, 900 + 90*i);
	w:AddCreature(crawler, -1500 - 90*i);
	w:AddCreature(tentacle, -900 - 90*i);
end

w:AddCreature(rabbit, 1425);

for i=0,30 do
	w:AddCreature(crawler, 2550 + 70*i);
	w:AddCreature(crawler, -2550 - 70*i);
end

print("Wave "..wave.." launched, good luck and SMASH'EM !");