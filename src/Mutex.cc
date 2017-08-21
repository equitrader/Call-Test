Mutex::Mutex(Team & team){
  dart_ret_t ret = dart_team_lock_init(team.dart_id(), &_mutex);
  ASSERT_EQ(DART_OK, ret, "dart_team_lock_init failed");
}

Mutex::~Mutex(){
  dart_ret_t ret = dart_team_lock_destroy(&_mutex);
  if (ret != DART_OK) {
   LOG_ERROR("Failed to destroy DART lock! "
                   "(dart_team_lock_free failed)");
  }
}

void Mutex::lock(){
  dart_ret_t ret = dart_lock_acquire(_mutex);
  ASSERT_EQ(DART_OK, ret, "dart_lock_acquire failed");
}
