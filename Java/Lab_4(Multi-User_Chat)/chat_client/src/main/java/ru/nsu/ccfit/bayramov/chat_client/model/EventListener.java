package ru.nsu.ccfit.bayramov.chat_client.model;

import java.util.List;

public interface EventListener {
    default void update(String eventType, List<String> userNames) { }

    default void update(String eventType, String userName) { }

    default void update(String eventType, String userName, String message) { }
}
