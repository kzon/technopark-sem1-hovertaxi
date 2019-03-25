#pragma once

namespace models {
	enum State {
		Order,
		SelectDriver, 
		WaitingForDriver,
		WaitingForClient, 
		InProgress,
		Finished, 
		Cancelled
	};
}