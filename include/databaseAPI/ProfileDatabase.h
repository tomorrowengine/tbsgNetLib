#pragma once
#include "core/SparseSet.h"
#include "memory/String.h"
#include "DatabaseAPI.h"

namespace net
{
	class Connection;
}


namespace tbsg
{
	enum class SessionTokenResponse
	{
		Success = 0,
		Invalid,
		InUse
	};

	/**
	 * \brief Manages the player profiles.
	 * \ingroup Database
	 */
	class ProfileDatabase
	{
	public:
		ProfileDatabase() = default;

		void Initialize(db::DatabaseAPI* api);

		SessionTokenResponse CheckSessionToken(net::Connection* connection, ptl::string token);
		/**
		 * \brief Load a profile using an id.
		 * \warning Should only be used to simulate games!
		 */
		bool LoadProfile(unsigned int profileId);

		const std::unordered_map<unsigned int, Profile>& GetProfiles() const;
		tbsg::Profile* GetProfile(net::Connection* connection);
		tbsg::Profile* GetProfile(unsigned int profileId);
		tbsg::Profile* GetProfileUsingConnection(unsigned int connectionId);

	private:
		db::DatabaseAPI* api{};
		std::unordered_map<unsigned int, Profile> profiles{};

		std::string prefix = "[ProfileDatabase]";

	};
}
