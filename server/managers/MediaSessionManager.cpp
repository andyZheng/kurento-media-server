#include "MediaSessionManager.h"
#include "types/MediaSessionImpl.h"

using namespace ::com::kurento::kms;
using namespace ::com::kurento::kms::api;

void task() {
}

MediaSessionManager::MediaSessionManager() {
}

MediaSessionManager::~MediaSessionManager() {
}

MediaSessionManager *MediaSessionManager::getInstance() {
	static MediaSessionManager *instance = new MediaSessionManager();
	return instance;
}

void MediaSessionManager::releaseInstance(MediaSessionManager* manager) {
	// As instance is a singleton no action is needed
}

MediaSession &MediaSessionManager::createMediaSession() {
	MediaSessionImpl *session = new MediaSessionImpl();

	mutex.lock();
	sessions.push_back(session);
	mutex.unlock();

	return *session;
}

void MediaSessionManager::deleteMediaSession(const MediaSession &session) {
	std::list<MediaSession *>::iterator it;
	bool found = FALSE;

	mutex.lock();
	for (it=sessions.begin(); !found && (it!=sessions.end()); it++) {
		if (session == *(*it)) {
			found = true;
			delete *it;
			sessions.erase(it);
		}
	}
	mutex.unlock();

	if (!found) {
		MediaSessionNotFoundException exception;
		throw exception;
	}
}