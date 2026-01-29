#include "converters/temperature.h"
#include "converters/distance.h"
#include "converters/weight.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>
#include <cstdio>

namespace
{
	enum class AppTab
	{
		temperature,
		distance,
		weight
	};

	struct TemperatureState
	{
		float input_value = 25.0f;
		int source_unit = 0;
		int target_unit = 1;
		double result = 0.0;
		bool needs_update = true;
	};

	struct DistanceState
	{
		float input_value = 100.0f;
		int source_unit = 0;
		int target_unit = 1;
		double result = 0.0;
		bool needs_update = true;
	};

	struct WeightState
	{
		float input_value = 1.0f;
		int source_unit = 0;
		int target_unit = 1;
		double result = 0.0;
		bool needs_update = true;
	};

	void updateTemperatureConversion(TemperatureState& state)
	{
		TemperatureUnit from = static_cast<TemperatureUnit>(state.source_unit);
		TemperatureUnit to = static_cast<TemperatureUnit>(state.target_unit);
		state.result = TemperatureConversion::convertTemperature(
			static_cast<double>(state.input_value),
			from,
			to
		);
		state.needs_update = false;
	}

	void updateDistanceConversion(DistanceState& state)
	{
		DistanceUnit from = static_cast<DistanceUnit>(state.source_unit);
		DistanceUnit to = static_cast<DistanceUnit>(state.target_unit);
		state.result = DistanceConversion::convertDistance(
			static_cast<double>(state.input_value),
			from,
			to
		);
		state.needs_update = false;
	}

	void updateWeightConversion(WeightState& state)
	{
		WeightUnit from = static_cast<WeightUnit>(state.source_unit);
		WeightUnit to = static_cast<WeightUnit>(state.target_unit);
		state.result = WeightConversion::convertWeight(
			static_cast<double>(state.input_value),
			from,
			to
		);
		state.needs_update = false;
	}

	void renderTemperatureTab(TemperatureState& state)
	{
		ImGui::Spacing();
		ImGui::Text("Temperature Converter");
		ImGui::Separator();
		ImGui::Spacing();

		const char* temp_units[] = {"Celsius", "Fahrenheit", "Kelvin"};
		const char* temp_symbols[] = {"\u00b0C", "\u00b0F", "K"};

		ImGui::Text("Input Value:");
		if (ImGui::InputFloat("##temp_input", &state.input_value, 0.1f, 1.0f, "%.2f"))
		{
			state.needs_update = true;
		}

		ImGui::Spacing();
		ImGui::Text("From:");
		if (ImGui::Combo("##temp_from", &state.source_unit, temp_units, 3))
		{
			state.needs_update = true;
		}

		ImGui::Spacing();
		ImGui::Text("To:");
		if (ImGui::Combo("##temp_to", &state.target_unit, temp_units, 3))
		{
			state.needs_update = true;
		}

		if (state.needs_update)
		{
			updateTemperatureConversion(state);
		}

		ImGui::Spacing();
		ImGui::Separator();
		ImGui::Spacing();

		ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.2f, 0.8f, 0.2f, 1.0f));
		ImGui::Text("Result:");
		ImGui::Text("%.2f %s = %.2f %s",
			state.input_value,
			temp_symbols[state.source_unit],
			state.result,
			temp_symbols[state.target_unit]
		);
		ImGui::PopStyleColor();
	}

	void renderDistanceTab(DistanceState& state)
	{
		ImGui::Spacing();
		ImGui::Text("Distance Converter");
		ImGui::Separator();
		ImGui::Spacing();

		const char* dist_units[] = {"Meters", "Feet", "Yards"};
		const char* dist_symbols[] = {"m", "ft", "yd"};

		ImGui::Text("Input Value:");
		if (ImGui::InputFloat("##dist_input", &state.input_value, 0.1f, 1.0f, "%.2f"))
		{
			state.needs_update = true;
		}

		ImGui::Spacing();
		ImGui::Text("From:");
		if (ImGui::Combo("##dist_from", &state.source_unit, dist_units, 3))
		{
			state.needs_update = true;
		}

		ImGui::Spacing();
		ImGui::Text("To:");
		if (ImGui::Combo("##dist_to", &state.target_unit, dist_units, 3))
		{
			state.needs_update = true;
		}

		if (state.needs_update)
		{
			updateDistanceConversion(state);
		}

		ImGui::Spacing();
		ImGui::Separator();
		ImGui::Spacing();

		ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.2f, 0.8f, 0.2f, 1.0f));
		ImGui::Text("Result:");
		ImGui::Text("%.2f %s = %.2f %s",
			state.input_value,
			dist_symbols[state.source_unit],
			state.result,
			dist_symbols[state.target_unit]
		);
		ImGui::PopStyleColor();
	}

	void renderWeightTab(WeightState& state)
	{
		ImGui::Spacing();
		ImGui::Text("Weight Converter");
		ImGui::Separator();
		ImGui::Spacing();

		const char* weight_units[] = {"Kilogram", "Pound", "Ounce"};
		const char* weight_symbols[] = {"kg", "lbs", "oz"};

		ImGui::Text("Input Value:");
		if (ImGui::InputFloat("##weight_input", &state.input_value, 0.1f, 1.0f, "%.2f"))
		{
			state.needs_update = true;
		}

		ImGui::Spacing();
		ImGui::Text("From:");
		if (ImGui::Combo("##weight_from", &state.source_unit, weight_units, 3))
		{
			state.needs_update = true;
		}

		ImGui::Spacing();
		ImGui::Text("To:");
		if (ImGui::Combo("##weight_to", &state.target_unit, weight_units, 3))
		{
			state.needs_update = true;
		}

		if (state.needs_update)
		{
			updateWeightConversion(state);
		}

		ImGui::Spacing();
		ImGui::Separator();
		ImGui::Spacing();

		ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.2f, 0.8f, 0.2f, 1.0f));
		ImGui::Text("Result:");
		ImGui::Text("%.2f %s = %.2f %s",
			state.input_value,
			weight_symbols[state.source_unit],
			state.result,
			weight_symbols[state.target_unit]
		);
		ImGui::PopStyleColor();
	}
}

static void glfwErrorCallback(int error, const char* description)
{
	fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}

int main(int, char**)
{
	glfwSetErrorCallback(glfwErrorCallback);
	if (!glfwInit())
	{
		return 1;
	}

	const char* glsl_version = "#version 130";
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

	GLFWwindow* window = glfwCreateWindow(600, 500, "OctoConverter - Unit Conversion Tool", nullptr, nullptr);
	if (window == nullptr)
	{
		return 1;
	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

	ImGui::StyleColorsDark();

	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init(glsl_version);

	AppTab current_tab = AppTab::temperature;
	TemperatureState temp_state;
	DistanceState dist_state;
	WeightState weight_state;

	const ImVec4 clear_color = ImVec4(0.15f, 0.15f, 0.15f, 1.00f);

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		{
			ImGui::SetNextWindowPos(ImVec2(0, 0));
			ImGui::SetNextWindowSize(ImGui::GetIO().DisplaySize);
			ImGui::Begin("OctoConverter", nullptr,
				ImGuiWindowFlags_NoResize |
				ImGuiWindowFlags_NoMove |
				ImGuiWindowFlags_NoCollapse |
				ImGuiWindowFlags_NoTitleBar
			);

			ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.3f, 0.7f, 1.0f, 1.0f));
			ImGui::SetWindowFontScale(1.5f);
			ImGui::Text("OCTO CONVERTER");
			ImGui::SetWindowFontScale(1.0f);
			ImGui::PopStyleColor();
			ImGui::Text("Professional Unit Conversion Tool by Pellenc");
			ImGui::Spacing();
			ImGui::Separator();
			ImGui::Spacing();

			if (ImGui::BeginTabBar("ConversionTabs"))
			{
				if (ImGui::BeginTabItem("Temperature"))
				{
					current_tab = AppTab::temperature;
					renderTemperatureTab(temp_state);
					ImGui::EndTabItem();
				}

				if (ImGui::BeginTabItem("Distance"))
				{
					current_tab = AppTab::distance;
					renderDistanceTab(dist_state);
					ImGui::EndTabItem();
				}

				if (ImGui::BeginTabItem("Weight"))
				{
					current_tab = AppTab::weight;
					renderWeightTab(weight_state);
					ImGui::EndTabItem();
				}

				ImGui::EndTabBar();
			}

			ImGui::Spacing();
			ImGui::Separator();
			ImGui::Spacing();
			ImGui::TextDisabled("Version 1.0.0 - Built with Dear ImGui");

			ImGui::End();
		}

		ImGui::Render();
		int display_w;
		int display_h;
		glfwGetFramebufferSize(window, &display_w, &display_h);
		glViewport(0, 0, display_w, display_h);
		glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
		glClear(GL_COLOR_BUFFER_BIT);
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		glfwSwapBuffers(window);
	}

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}
