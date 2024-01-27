#pragma once

class TextureRect
{
public:
    TextureRect(Vector3 position, Vector3 size, float rotation, wstring path);
    TextureRect(Vector3 position, Vector3 size, float rotation);
    ~TextureRect();

    void Update();
    void Render();

    void Update(Vector3 position);
    void Update(Vector3 position, Vector3 size);

    //void Collision();

    void SetShader(wstring shaderPath);
    void SetSRV(ID3D11ShaderResourceView* srv) { this->srv = srv; }

    void MapVertexBuffer();
    void UnmapVertexBuffer();

    const Vector3 GetPosition() { return position; }
    const Vector3 GetSize() { return size; }
    const float GetRotation() { return rotation; }
    const wstring GetImagePath() { return imagePath; }
    //void SetPosition(Vector3 position, Vector3 size);

    BoundingBox* GetBox() { return box; }

protected:
    vector<VertexTexture> vertices;
    VertexBuffer* vb = nullptr;

    vector<uint> indices;
    IndexBuffer* ib = nullptr;

    InputLayout* il = nullptr;

    VertexShader* vs = nullptr;
    PixelShader* ps = nullptr;

    Matrix world;
    Matrix S, R, T;

    WorldBuffer* wb = nullptr;

    Vector3 position;
    Vector3 size;
    float rotation;

    wstring imagePath;

    ID3D11ShaderResourceView* srv = nullptr;

    D3D11_MAPPED_SUBRESOURCE subResource;

    //Monster* m1 = nullptr;
    //Player* p1 = nullptr;

private:
    ID3D11SamplerState* point[2];
    ID3D11BlendState* bPoint[2];

    //test
    BoundingBox* box;
};