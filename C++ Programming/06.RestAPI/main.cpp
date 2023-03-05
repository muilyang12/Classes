#include <iostream>
#include <cpprest/http_client.h>
#include <cpprest/filestream.h>
#include <cpprest/uri.h>
#include <cpprest/json.h>

using namespace utility;
using namespace web;
using namespace web::http;
using namespace web::http::client;
using namespace concurrency::streams;

auto POST_request() {
	auto postJson = pplx::create_task([]() {
		json::value jsonObject;
		jsonObject[U("id")] = json::value::string(U("string"));
		jsonObject[U("password")] = json::value::string(U("string"));

		return http_client(U("http://localhost:8000"))
			.request(methods::POST,
				uri_builder(U("login")).to_string(),
				jsonObject.serialize(), U("application/json"));
	})

	.then([](http_response response) {
		// Convert the response body to JSON object.
		return response.extract_json();
	})

	.then([](json::value jsonObject) {
		std::wcout << "========== Result ==========\n"
			<< "accessToken: " << jsonObject[U("accessToken")].as_string() << "\n"
			<< "expiresIn: " << jsonObject[U("expiresIn")].as_integer() << "\n"
			<< std::endl;
	});

	return postJson;
}

int main()
{
	try {
		POST_request().wait();
	}
	catch (const std::exception& e) {
		printf("Error exception: %s\n", e.what());
	}

	return 0;
}