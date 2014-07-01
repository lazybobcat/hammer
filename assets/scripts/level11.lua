SLB.using(SLB);

local w = World.Instance();
local wave = 11;
local boss_crawler = 1;

w:AddBoss(boss_crawler, 110);
w:AddBoss(boss_crawler, -110);


print("Wave "..wave.." launched, good luck and SMASH'EM !");