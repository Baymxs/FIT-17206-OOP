package ru.nsu.ccfit.bayramov.Minesweeper.Controller;

import javafx.collections.ObservableList;
import javafx.concurrent.Task;
import javafx.event.Event;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.input.MouseButton;
import javafx.scene.layout.GridPane;
import javafx.stage.Stage;
import ru.nsu.ccfit.bayramov.Minesweeper.Model.GameModel;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.URL;
import java.util.ArrayList;
import java.util.List;
import java.util.Properties;
import java.util.ResourceBundle;

public class GameController implements Initializable {
    private final static Image simpleCell = new Image("ru/nsu/ccfit/bayramov/Minesweeper/field.png");
    private final static Image movedCell = new Image("ru/nsu/ccfit/bayramov/Minesweeper/moved_field.png");
    private final static Image flaggedCell = new Image("ru/nsu/ccfit/bayramov/Minesweeper/field_with_flag.png");
    private final static Image zeroCell = new Image("ru/nsu/ccfit/bayramov/Minesweeper/zero.png");
    private final static Image oneCell = new Image("ru/nsu/ccfit/bayramov/Minesweeper/one.png");
    private final static Image twoCell = new Image("ru/nsu/ccfit/bayramov/Minesweeper/two.png");
    private final static Image threeCell = new Image("ru/nsu/ccfit/bayramov/Minesweeper/three.png");
    private final static Image fourCell = new Image("ru/nsu/ccfit/bayramov/Minesweeper/four.png");
    private final static Image minedCell = new Image("ru/nsu/ccfit/bayramov/Minesweeper/mine.png");
    private final static Image explosionCell = new Image("ru/nsu/ccfit/bayramov/Minesweeper/explosion.png");
    private final static Image simpleBackButton = new Image("ru/nsu/ccfit/bayramov/Minesweeper/Buttons/BackButton/back_button.png");
    private final static Image movedBackButton = new Image("ru/nsu/ccfit/bayramov/Minesweeper/Buttons/BackButton/moved_back_button.png");

    private Properties scoresProperties = new Properties();

    @FXML
    private GridPane cellsPanel;

    @FXML
    private ImageView backButton;

    @FXML
    private Label timerLabel;

    @FXML
    private Label fakeTimerLabel;

    @FXML
    private Label flags;

    private GameModel gameModel = GameModel.getInstance();

    @Override
    public void initialize(URL location, ResourceBundle resources) {
        List<ImageView> cells = new ArrayList<>();

        Task startGame = new Task<Integer>() {
            @Override
            protected Integer call() {
                while (true) {
                    if (!gameModel.getGameState()) {
                        break;
                    }
                    updateMessage(Integer.toString(gameModel.getCurrentTime()));
                }
                return 0;
            }
        };
        timerLabel.textProperty().bind(startGame.messageProperty());

        for (int i = 0; i < gameModel.getNumOfColumns() * gameModel.getNumOfRows(); i++) {
            ImageView cell = new ImageView(simpleCell);

            cells.add(cell);

            cellsPanel.add(cells.get(i), i % gameModel.getNumOfColumns(), i / gameModel.getNumOfRows());
            cell.setOnMouseClicked(event->{
                if (event.getButton() == MouseButton.SECONDARY) {
                    if (gameModel.getGameState()) {
                        if (cell.getImage().equals(flaggedCell)) {
                            if (gameModel.flagsDecrement()) {
                                cell.setImage(simpleCell);
                                flags.setText(Integer.toString(gameModel.getNumOfCurrentFlags()));
                            }
                        } else if (cell.getImage().equals(movedCell)) {
                            if (gameModel.flagsIncrement()) {
                                cell.setImage(flaggedCell);
                                flags.setText(Integer.toString(gameModel.getNumOfCurrentFlags()));
                            }
                        }
                    }
                } else if (event.getButton() == MouseButton.PRIMARY) {
                    if (!gameModel.getGameState() && gameModel.isFromMenuWindow()) {
                        System.out.println(gameModel.getNumOfOpenedCells());

                        fakeTimerLabel.setText("");
                        gameModel.setFromMenuWindow(false);
                        gameModel.newGame();

                        Thread thread = new Thread(startGame);
                        thread.setDaemon(true);
                        thread.start();

                        openCell(cell);
                        System.out.println(gameModel.getNumOfOpenedCells());
                    } else if (!cell.getImage().equals(flaggedCell)) {
                        if (gameModel.isMine(GridPane.getRowIndex(cell), GridPane.getColumnIndex(cell))) {
                            cell.setImage(explosionCell);
                            gameModel.setCellOpen(GridPane.getRowIndex(cell), GridPane.getColumnIndex(cell));
                            drawClosedCells();
                            gameModel.finishGame();
                        } else {
                            openCell(cell);
                            if (gameModel.getNumOfOpenedCells() == gameModel.getNumOfColumns() * gameModel.getNumOfRows() - gameModel.getNumOfTotalMines()) {
                                drawClosedCells();
                                gameModel.setNewResult(Integer.getInteger(timerLabel.getText()));
                                gameModel.finishGame();
                                System.out.println(gameModel.getGameState());
                            }
                        }
                    }
                }
            });
            cell.setOnMouseMoved(event -> {
                if (cell.getImage().equals(simpleCell)) {
                    cell.setImage(movedCell);
                }
            });

            cell.setOnMouseExited(event -> {
                if (cell.getImage().equals(movedCell)) {
                    cell.setImage(simpleCell);
                }
            });
        }
    }

    private ImageView getNodeByRowColumnIndex (final int row, final int column, GridPane gridPane) {
        Node result = null;
        ObservableList<Node> childrens = gridPane.getChildren();

        for (Node node : childrens) {
            if(gridPane.getRowIndex(node) == row && gridPane.getColumnIndex(node) == column) {
                result = node;
                break;
            }
        }

        return (ImageView) result;
    }

    private void openCell(ImageView cell) {
        gameModel.setCellOpen(GridPane.getRowIndex(cell), GridPane.getColumnIndex(cell));

        switch (gameModel.getNumOfMinesAround(GridPane.getRowIndex(cell), GridPane.getColumnIndex(cell))) {
            case 0:
                cell.setImage(zeroCell);
                gameModel.findEmptyCells(GridPane.getRowIndex(cell), GridPane.getColumnIndex(cell));
                drawOpenedCells();
                break;
            case 1:
                cell.setImage(oneCell);
                break;
            case 2:
                cell.setImage(twoCell);
                break;
            case 3:
                cell.setImage(threeCell);
                break;
            case 4:
                cell.setImage(fourCell);
                break;
        }
    }

    private void drawCellByCoords(int x, int y, int numOfMines) {
        switch (numOfMines) {
            case 0:
                getNodeByRowColumnIndex(x, y, cellsPanel).setImage(zeroCell);
                break;
            case 1:
                getNodeByRowColumnIndex(x, y, cellsPanel).setImage(oneCell);
                break;
            case 2:
                getNodeByRowColumnIndex(x, y, cellsPanel).setImage(twoCell);
                break;
            case 3:
                getNodeByRowColumnIndex(x, y, cellsPanel).setImage(threeCell);
                break;
            case 4:
                getNodeByRowColumnIndex(x, y, cellsPanel).setImage(fourCell);
                break;
        }
    }

    private void drawOpenedCells() {
        for (int i = 0; i < gameModel.getNumOfRows(); i++) {
            for (int j = 0; j < gameModel.getNumOfColumns(); j++) {
                if (gameModel.isCellOpen(i, j)) {
                    drawCellByCoords(i, j, gameModel.getNumOfMinesAround(i, j));
                }
            }
        }
    }

    private void drawClosedCells() {
        for (int i = 0; i < gameModel.getNumOfRows(); i++) {
            for (int j = 0; j < gameModel.getNumOfColumns(); j++) {
                if (!gameModel.isCellOpen(i, j)) {
                    if (gameModel.isMine(i, j)) {
                        getNodeByRowColumnIndex(i, j, cellsPanel).setImage(minedCell);
                    } else {
                        drawCellByCoords(i, j, gameModel.getNumOfMinesAround(i, j));
                    }
                }
            }
        }
    }

    public void backButtonClicked(Event event) throws IOException {
        gameModel.finishGame();

        Parent menuViewParent = FXMLLoader.load(getClass().getResource("../View/Menu.fxml"));

        Scene menuViewScene = new Scene(menuViewParent);

        Stage window = (Stage)((Node)event.getSource()).getScene().getWindow();

        window.setScene(menuViewScene);
        window.show();
    }

    public void backButtonMoved() {
        backButton.setImage(movedBackButton);
    }

    public void backButtonExited() {
        backButton.setImage(simpleBackButton);
    }
}
