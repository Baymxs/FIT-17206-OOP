package ru.nsu.ccfit.bayramov.chat_client.model;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class EventManager {
    private Map<String, List<EventListener>> listeners = new HashMap<>();

    public EventManager(String... operations) {
        for (String operation : operations) {
            listeners.put(operation, new ArrayList<>());
        }
    }

    public void subscribe(EventListener listener, String... eventTypes) {
        for (String eventType : eventTypes) {
            listeners.get(eventType).add(listener);
        }
    }

    public void unsubscribe(EventListener listener, String... eventTypes) {
        for (String eventType : eventTypes) {
            listeners.get(eventType).remove(listener);
        }
    }

    public void unsubscribeAll(String... eventTypes) {
        for (String eventType : eventTypes) {
            listeners.get(eventType).clear();
        }
    }

    public void notify(String eventType, List<String> userNames) {
        List<EventListener> users = listeners.get(eventType);
        for (EventListener listener : users) {
            listener.update(eventType, userNames);
        }
    }

    public void notify(String eventType, String message) {
        List<EventListener> users = listeners.get(eventType);
        for (EventListener listener : users) {
            listener.update(eventType, message);
        }
    }

    public void notify(String eventType, String userName, String lastMessage) {
        List<EventListener> users = listeners.get(eventType);
        for (EventListener listener : users) {
            listener.update(eventType, userName, lastMessage);
        }
    }


}
