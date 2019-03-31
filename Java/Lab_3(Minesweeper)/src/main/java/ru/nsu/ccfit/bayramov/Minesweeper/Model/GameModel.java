package ru.nsu.ccfit.bayramov.Minesweeper.Model;

import java.io.*;
import java.util.*;

public class GameModel {

    private static GameModel instance = new GameModel();

    private Properties scoresProperties = new Properties();

    private int rows;
    private int columns;
    private int numOfMines;
    private int numOfOpenedCells;
    private int numOfCurrentFlags;
    private int gameMaxTime;
    private int currentTime;
    private boolean gameState;
    private boolean fromMenuWindow;

    private Cell[][] cells;


    private GameModel() {
        rows = 9;
        columns = 9;
        numOfMines = 10;
        numOfOpenedCells = 0;
        numOfCurrentFlags = numOfMines;
        gameMaxTime = 600;
        currentTime = 0;
        gameState = false;
        fromMenuWindow = false;
    }

    public static GameModel getInstance() {
        return instance;
    }

    public int getNumOfRows() {
        return rows;
    }

    public int getNumOfColumns() {
        return columns;
    }

    public int getNumOfMinesAround(int x, int y) {
        return cells[x][y].getMinesAround();
    }

    public int getNumOfOpenedCells() {
        return numOfOpenedCells;
    }

    public int getNumOfTotalMines() {
        return numOfMines;
    }

    public int getNumOfCurrentFlags() {
        return numOfCurrentFlags;
    }

    public boolean flagsIncrement() {
        numOfCurrentFlags--;
        return true;
    }

    public boolean flagsDecrement() {
        if (numOfCurrentFlags < numOfMines) {
            numOfCurrentFlags++;
            return true;
        }
        return false;
    }

    public int getCurrentTime() {
        return currentTime;
    }

    public boolean getGameState() {
        return gameState;
    }

    public boolean isFromMenuWindow() {
        return fromMenuWindow;
    }

    public void setFromMenuWindow(boolean fromMenuWindow) {
        this.fromMenuWindow = fromMenuWindow;
    }

    private void initCells() {
        cells = new Cell[rows][columns];

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                cells[i][j] = new Cell();
            }
        }
    }

    public boolean isMine(int x, int y) {
        return cells[x][y].isMined();
    }

    public boolean isCellOpen(int x, int y) {
        return cells[x][y].isOpened();
    }

    public void setCellOpen(int x, int y) {
        cells[x][y].setOpen(true);
        numOfOpenedCells++;
    }

    private void setMines() {
        Random random = new Random();

        int minesCount = 0;

        while (minesCount != numOfMines) {
            int randX = random.nextInt(rows);
            int randY = random.nextInt(columns);

            if (!cells[randX][randY].isMined()) {
                cells[randX][randY].setMine(true);
                minesCount++;
            }
        }
    }

    private void setMinesCount() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (!cells[i][j].isMined()) {
                    int count = countMinesAround(i, j);
                    cells[i][j].setMinesAround(count);
                }
            }
        }
    }

    private int countMinesAround(int x, int y) {
        int count = 0;

        for (int i = -1; i <= 1; i++) {
            int xx = x + i;

            if (xx < 0 || xx >= columns) {
                continue;
            }

            for (int j = -1; j <= 1; j++) {
                int yy = y + j;

                if (yy < 0 || yy >= rows) {
                    continue;
                }

                if (i == 0 && j == 0) {
                    continue;
                }

                if (cells[xx][yy].isMined()) {
                    count++;
                }
            }
        }

        return count;
    }

    private boolean checkEmptiness(Cell cell) {
        if (!cell.isOpened()) {
            return cell.isEmpty();
        }
        return false;
    }

    private void openAroundCells(int x, int y) {
        for (int i = -1; i <= 1; i++) {
            int xx = x + i;

            if (xx < 0 || xx >= columns) {
                continue;
            }

            for (int j = -1; j <= 1; j++) {
                int yy = y + j;

                if (yy < 0 || yy >= rows) {
                    continue;
                }

                if (i == 0 && j == 0) {
                    continue;
                }

                if (!cells[xx][yy].isEmpty() && !cells[xx][yy].isOpened()) {
                    setCellOpen(xx, yy);
                }
            }
        }
    }

    public void findEmptyCells(int x, int y) {
        for (int i = -1; i <= 1; i++) {
            int xx = x + i;

            if (xx < 0 || xx >= columns) {
                continue;
            }

            for (int j = -1; j <= 1; j++) {
                int yy = y + j;

                if (yy < 0 || yy >= rows) {
                    continue;
                }

                if (i == 0 && j == 0) {
                    continue;
                }

                if (checkEmptiness(cells[xx][yy])) {
                    setCellOpen(xx, yy);

                    openAroundCells(xx, yy);
                    findEmptyCells(xx, yy);
                }
            }
        }
    }

    public void newGame() {
        gameState = true;
        numOfCurrentFlags = numOfMines;
        currentTime = 0;
        numOfOpenedCells = 0;

        initCells();
        setMines();
        setMinesCount();

        new Timer(true).schedule(
                new TimerTask() {
                    @Override
                    public void run() {
                        if (currentTime == gameMaxTime || !gameState) {
                            this.cancel();
                            gameState = false;
                        } else {
                            currentTime++;
                        }
                    }
                }, 0, 1000);
    }

    public void setNewResult(int result) {
        try {
            scoresProperties.load(GameModel.class.getClassLoader().getResourceAsStream("ru/nsu/ccfit/bayramov/Minesweeper/scores.properties"));
        } catch (IOException e) {
            e.printStackTrace();
        }

        for (int i = 0; i < 5; i++) {
            if (Integer.parseInt(scoresProperties.getProperty(Integer.toString(i))) == 0) {
                scoresProperties.setProperty(Integer.toString(i), Integer.toString(result));
                try (FileOutputStream out = new FileOutputStream("src/main/resources/ru/nsu/ccfit/bayramov/Minesweeper/scores.properties")) {
                    scoresProperties.store(out, null);
                } catch (IOException e) {
                    e.printStackTrace();
                }
                break;
            } else {
                if (result < Integer.parseInt(scoresProperties.getProperty(Integer.toString(i)))) {
                    scoresProperties.setProperty(Integer.toString(i), Integer.toString(i));
                    try (FileOutputStream out = new FileOutputStream("src/main/resources/ru/nsu/ccfit/bayramov/Minesweeper/scores.properties")) {
                        scoresProperties.store(out, null);
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                    break;
                }
            }
        }
    }

    public void finishGame() {
        gameState = false;
    }
}