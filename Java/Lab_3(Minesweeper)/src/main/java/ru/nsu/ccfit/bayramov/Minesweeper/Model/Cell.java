package ru.nsu.ccfit.bayramov.Minesweeper.Model;

class Cell {
    private int minesAround;
    private boolean mine;
    private boolean open;

    Cell() {
        minesAround = 0;
        mine = false;
        open = false;
    }

    int getMinesAround() {
        return minesAround;
    }

    void setMinesAround(int minesAround) {
        this.minesAround = minesAround;
    }

    boolean isMined() {
        return mine;
    }

    void setMine(boolean mine) {
        this.mine = mine;
    }

    boolean isOpened() {
        return open;
    }

    void setOpen(boolean open) {
        this.open = open;
    }

    boolean isEmpty() {
        return minesAround == 0;
    }
}
