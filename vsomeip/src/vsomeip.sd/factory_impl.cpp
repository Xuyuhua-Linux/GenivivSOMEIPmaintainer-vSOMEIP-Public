//
// factory_impl.cpp
//
// This file is part of the BMW Some/IP implementation.
//
// Copyright �� 2013, 2014 Bayerische Motoren Werke AG (BMW).
// All rights reserved.
//

#include <vsomeip_internal/sd/factory_impl.hpp>
#include <vsomeip_internal/sd/client_manager_impl.hpp>
#include <vsomeip_internal/sd/message_impl.hpp>
#include <vsomeip_internal/sd/service_manager_impl.hpp>

namespace vsomeip {
namespace sd {

factory * factory_impl::get_instance() {
	static factory_impl the_factory;
	return &the_factory;
}

factory_impl::~factory_impl() {
}

client_manager * factory_impl::create_client_manager(
					boost::asio::io_service &_service) const {
	return new client_manager_impl(_service);
}

service_manager * factory_impl::create_service_manager(
					boost::asio::io_service &_service) const {
	return new service_manager_impl(_service);
}

message * factory_impl::create_message() const {
	return new message_impl;
}

} // namespace sd
} // namespace vsomeip

