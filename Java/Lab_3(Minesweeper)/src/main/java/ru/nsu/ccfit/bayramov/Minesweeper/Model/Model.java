package ru.nsu.ccfit.bayramov.Minesweeper.Model;

public class Model {
    private String gameStage;
    private long seconds;

    public void setGameStage(String gameStage) {
        this.gameStage = gameStage;
    }

    public String getGameStage() {
        return gameStage;
    }

    public void startGame() {
        seconds = System.currentTimeMillis();
    }

    public void getTime() {

    }

}
