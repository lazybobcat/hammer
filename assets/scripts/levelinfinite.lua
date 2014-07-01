SLB.using(SLB);

local w = World.Instance();
local wave = 16;
local rabbit = 1;
local tentacle = 2;
local crawler = 3;
local boss_crawler = 1;
local boss_tentacle = 2;
local boss_megacrawler = 3;

w:AddBoss(boss_crawler, 110);
w:AddBoss(boss_crawler, -110);
w:AddBoss(boss_tentacle, 160);
w:AddBoss(boss_tentacle, -160);
w:AddBoss(boss_megacrawler, 160);


for i=0,30 do
	w:AddCreature(crawler, 2550 + 70*i);
	w:AddCreature(crawler, -2550 - 70*i);
end

print("Last Wave launched, good luck and SMASH'EM !");