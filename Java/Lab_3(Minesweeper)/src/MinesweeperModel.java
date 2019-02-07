public class MinesweeperModel {
    private String gameMode;
    private StringBuilder gameStage;

    MinesweeperModel(String gameMode) {
        this.gameMode = gameMode;
        gameStage = new StringBuilder("Menu");
    }

    String getGameMode() {
        return gameMode;
    }

    String getGameStage() {
        return gameStage.toString();
    }
}
