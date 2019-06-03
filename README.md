# kimm_visualize

kimm_visualize_pkg 폴더의 소스파일을 빌드.
kimm_visualize/rviz_visualization/kimm_visualize_pkg/src/kimm_visualize/src/ 내부의
eight_octomap_kimm.cpp 노드는 파일을 읽어와 pointcloudXYZ 메시지 타입으로 변환해 publish하는 역할.
eight_octomap_kimm.cpp 는 rosrun kimm_visualize eight_octomap 명령어를 사용해 실행.

eight_octomap을 실행한 후,
kimm_visualize/rviz_visualization/octomap/
파일을 octomap_server의 launch 파일에 추가한 후,
roslaunch octomap_server octomap_eight_kimm.launch 를 통해 실행하면

위의 eight_octomap 노드의 정보를 받아와 octomap 지도 생성
생성된 지도는 rviz 상에서 확인 가능.

