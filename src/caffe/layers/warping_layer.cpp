#include <algorithm>
#include <cfloat>
#include <vector>


#include "caffe/common.hpp"
#include "caffe/layer.hpp"
#include "caffe/syncedmem.hpp"
#include "caffe/util/math_functions.hpp"
#include "../../../include/caffe/layers/warping_layer.hpp"

namespace caffe {
template <typename Dtype>
void WarpingLayer<Dtype>::LayerSetUp(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {
 // validate number of bottom and top blobs
 CHECK_EQ(3,bottom.size())<< "We need 3 bottoms: Image, horizontal flow and verical flow";
 CHECK_EQ(1,top.size())<< "Output is only warp image";
 CHECK_EQ(bottom[0]->num(),bottom[1]->num())<< " Input image and the flow should have same number of instances";
 CHECK_EQ(bottom[0]->height(),bottom[1]->height())<< " Input image and the flow should have same height";
 CHECK_EQ(bottom[0]->width(),bottom[1]->width())<< " Input image and the flow should have same width";
 CHECK_EQ(bottom[2]->num(),bottom[1]->num())<< " horizontal and vertical flow should have same number of instances";
 CHECK_EQ(bottom[2]->height(),bottom[1]->height())<< " horizontal and vertical flow should have same height";
 CHECK_EQ(bottom[2]->width(),bottom[1]->width())<< " horizontal and vertical flow should have same width";

}

template <typename Dtype>
void WarpingLayer<Dtype>::Reshape(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {
 CHECK_EQ(4, bottom[0]->num_axes()) << "Input must have 4 axes, "
      << "corresponding to (num, channels, height, width)";
 channels_ = bottom[0]->channels();
 height_ = bottom[0]->height();
 width_ = bottom[0]->width();
 top[0]->Reshape(bottom[0]->num(), channels_,height_,width_);
 //warp_image.Reshape(bottom[0]->num(), channels_,height_,width_);
}


template <typename Dtype>
void WarpingLayer<Dtype>::Forward_cpu(const vector<Blob<Dtype>*>& bottom,
      const vector<Blob<Dtype>*>& top) {
  /*const Dtype* Image2Warp = bottom[0]->cpu_data();
  const Dtype* u = bottom[1]->cpu_data();
  const Dtype* v = bottom[2]->cpu_data();

  Dtype* top_data = top[0]->mutable_cpu_data();
  const int top_count = top[0]->count();
 */
  // For this moment we only have GPU
  CHECK_EQ(1,0)<< "Layer does not exist on CPU haha";
}


template <typename Dtype>
void WarpingLayer<Dtype>::Backward_cpu(const vector<Blob<Dtype>*>& top,
      const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom) {
  if (!propagate_down[0]) {
    return;
  }
 
  // For this moment we only have GPU
  CHECK_EQ(1,0)<< "Layer does not exist on CPU haha";

}



#ifdef CPU_ONLY
STUB_GPU(WarpingLayer);
#endif

INSTANTIATE_CLASS(WarpingLayer);
REGISTER_LAYER_CLASS(Warping);
}  // namespace caffe




