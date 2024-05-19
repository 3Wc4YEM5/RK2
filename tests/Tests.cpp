#include <gtest/gtest.h>
#include <main.cpp>

TEST(EnemyAgentTest, GotShot) {
  Tank tank(5, 0);
  Bomb bomb(3);
  EXPECT_EQ(tank.gotShot(5), 1);
  EXPECT_EQ(tank.gotShot(6), 0);
  EXPECT_EQ(bomb.gotShot(3), -2);
  EXPECT_EQ(bomb.gotShot(4), 0);
}

TEST(BonusAgentTest, Hit) {
  Gift gift(5);
  Life life(3);

  EXPECT_EQ(gift.hit(5), 2);
  EXPECT_EQ(gift.hit(6), 0);
  EXPECT_EQ(life.hit(3), 3);
  EXPECT_EQ(life.hit(4), 0);
}

TEST(FactoryTest, CreateAgents) {
  CombatGameFactory combatFactory;
  MineSweepGameFactory mineFactory;

  EnemyAgent* tank = combatFactory.createEnemyAgent();
  EnemyAgent* bomb = mineFactory.createEnemyAgent();
  BonusAgent* gift = combatFactory.createBonusAgentGift();
  BonusAgent* life = mineFactory.createBonusAgentGift();

  EXPECT_TRUE(dynamic_cast<Tank*>(tank));
  EXPECT_TRUE(dynamic_cast<Bomb*>(bomb));
  EXPECT_TRUE(dynamic_cast<Gift*>(gift));
  EXPECT_TRUE(dynamic_cast<Life*>(life));
}