SLB.using(SLB);

local w = World.Instance();
local wave = 6;
local rabbit = 1;
local tentacle = 2;
local crawler = 3;

for i=0,10 do
	w:AddCreature(tentacle, 10 + 70*i);
	w:AddCreature(tentacle, -20 - 70*i);
end

for i=0,10 do
	w:AddCreature(tentacle, 800 + 80*i);
	w:AddCreature(tentacle, -800 - 80*i);
end

for i=0,10 do
	w:AddCreature(tentacle, 1600 + 90*i);
	w:AddCreature(crawler, 900 + 90*i);
	w:AddCreature(tentacle, -1600 - 90*i);
	w:AddCreature(crawler, -900 - 90*i);
end

w:AddCreature(rabbit, -1425);
w:AddCreature(rabbit, 1425);

print("Wave "..wave.." launched, good luck and SMASH'EM !");