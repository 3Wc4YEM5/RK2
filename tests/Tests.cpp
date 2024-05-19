#include <gtest/gtest.h>
#include <main.cpp>

TEST(GameTest, ConstructorAndDestructor) {
  Game game;
  EXPECT_NO_THROW(game.~Game());
}

TEST(GameTest, Start) {
  Game game;

  // Создаем два фиктивных уровня
  Factory* factory1 = new CombatGameFactory();
  Factory* factory2 = new MineSweepGameFactory();

  game.addLevel(factory1);
  game.addLevel(factory2);

  // Запускаем игру и проверяем, что она завершается успешно
  EXPECT_NO_THROW(game.start());
}

TEST(GameTest, StartLevel) {
  Game game;

  // Создаем фиктивный уровень
  Factory* factory = new CombatGameFactory();

  bool result = game.startLevel(factory);
  EXPECT_TRUE(result);  // Ожидаем, что уровень будет завершен успешно
}
