#include <obs-module.h>
#include <obs-frontend-api.h>
#include <QtWidgets>
#include <cstring>

OBS_DECLARE_MODULE()
OBS_MODULE_USE_DEFAULT_LOCALE(PLUGIN_NAME, "en-US")


struct test_filter_info {
	obs_source_t* source;
	gs_effect_t* effect;
};


static const char* test_filter_get_name(void* unused) {
	UNUSED_PARAMETER(unused);
	return "Test Filter";
}
static obs_properties_t* test_filter_get_properties(void* data) {
	test_filter_info* test_filter = (test_filter_info*) data;

	obs_properties_t* properties = obs_properties_create();
	obs_properties_set_param(properties, test_filter, NULL);

	obs_properties_add_int(properties, "int_input", "Integer Input", 0, 9999, 1);

	return properties;
}
static void* test_filter_create(obs_data_t* settings, obs_source_t* source) {
	QMessageBox::information(nullptr, "Test Plugin", "Initializing...", QMessageBox::Ok);
	QMainWindow* main_window = reinterpret_cast<QMainWindow*>(obs_frontend_get_main_window());
	if(main_window) QMessageBox::information(nullptr, "Test Plugin", "Initializing...", QMessageBox::Ok);
	
	for(auto& child : main_window->children()) {
		if(strcmp(child->metaObject()->className(), "OBSBasicFilters") != 0) continue;

		QMessageBox::information(nullptr, "in: QMainWindows", child->metaObject()->className(), QMessageBox::Ok);
		QDialog* filters = reinterpret_cast<QDialog*>(child);
		
		QFrame* properties_frame = filters->findChild<QFrame*>("propertiesFrame");
		QMessageBox::information(nullptr, "in: OBSBasicFilters", properties_frame->metaObject()->className(), QMessageBox::Ok);

		for(auto& child : properties_frame->children()) {
			if(strcmp(child->metaObject()->className(), "OBSPropertiesView") != 0) continue;
			QScrollArea* view = reinterpret_cast<QScrollArea*>(child);
			QMessageBox::information(nullptr, "in: propertiesFrame", view->metaObject()->className(), QMessageBox::Ok);
			QMessageBox::information(nullptr, "OBSPropertiesView.widget", view->widget()->metaObject()->className(), QMessageBox::Ok);
			QMessageBox::information(nullptr, "QWidget.layout", view->widget()->layout()->metaObject()->className(), QMessageBox::Ok);
			((QFormLayout*)view->widget()->layout())->removeRow(0);
			QMessageBox::information(nullptr, "QWidget.layout", "Removed row!", QMessageBox::Ok);
		}
	}


	test_filter_info* test_filter = new test_filter_info;
	return test_filter;
}
static void test_filter_destroy(void* data) {
	test_filter_info* test_filter = (test_filter_info*) data;
}





static obs_source_info* test_filter() {
	obs_source_info* test_filter = new obs_source_info;
	test_filter->id = "test_filter";
	test_filter->type = OBS_SOURCE_TYPE_FILTER;
	test_filter->output_flags = OBS_SOURCE_VIDEO;
	test_filter->get_name = test_filter_get_name;
	test_filter->create = test_filter_create;
	test_filter->destroy = test_filter_destroy;
	test_filter->get_properties = test_filter_get_properties;
	return test_filter;
}



bool obs_module_load(void)
{
	obs_register_source(test_filter());
	return true;
}

void obs_module_unload(void)
{
	
}
